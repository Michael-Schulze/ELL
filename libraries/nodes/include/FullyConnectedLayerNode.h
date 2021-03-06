////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     FullyConnectedLayerNode.h (nodes)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NeuralNetworkLayerNode.h"

#include <model/include/IRMapCompiler.h>
#include <model/include/ModelTransformer.h>
#include <model/include/PortElements.h>

#include <predictors/neural/include/FullyConnectedLayer.h>

#include <string>
#include <type_traits>

namespace ell
{
namespace nodes
{
    /// <summary> A node that wraps a neural net FullyConnectedLayer. </summary>
    template <typename ValueType>
    class FullyConnectedLayerNode : public NeuralNetworkLayerNode<FullyConnectedLayerNode<ValueType>, predictors::neural::FullyConnectedLayer<ValueType>, ValueType>
    {
    public:
        using LayerType = predictors::neural::FullyConnectedLayer<ValueType>;
        using BaseType = NeuralNetworkLayerNode<FullyConnectedLayerNode<ValueType>, predictors::neural::FullyConnectedLayer<ValueType>, ValueType>;

        /// @name Input and Output Ports
        /// @{
        using BaseType::input;
        using BaseType::output;
        /// @}

        FullyConnectedLayerNode() = default;

        /// <summary> Constructor from a layer. </summary>
        ///
        /// <param name="input"> </param>
        /// <param name="layer"> The bias layer to wrap. </param>
        FullyConnectedLayerNode(const model::OutputPort<ValueType>& input, const predictors::neural::FullyConnectedLayer<ValueType>& layer);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return utilities::GetCompositeTypeName<ValueType>("FullyConnectedLayerNode"); }

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        std::string GetRuntimeTypeName() const override { return GetTypeName(); }

        /// <summary> Indicates if this node is able to compile itself to code. </summary>
        bool IsCompilable(const model::MapCompiler* compiler) const override { return false; }

    protected:
        bool Refine(model::ModelTransformer& transformer) const override;

    private:
        void Copy(model::ModelTransformer& transformer) const override;
    };
} // namespace nodes
} // namespace ell
