////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     ActivationLayerNode.h (nodes)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NeuralNetworkLayerNode.h"

#include <model/include/IRMapCompiler.h>
#include <model/include/ModelTransformer.h>
#include <model/include/PortElements.h>

#include <predictors/neural/include/ActivationLayer.h>
#include <predictors/neural/include/ParametricReLUActivation.h>

#include <string>
#include <type_traits>

namespace ell
{
namespace nodes
{
    //
    // The ActivationLayerNode
    //

    /// <summary> A node that wraps a neural net ActivationLayer. </summary>
    template <typename ValueType>
    class ActivationLayerNode
        : public NeuralNetworkLayerNode<ActivationLayerNode<ValueType>, predictors::neural::ActivationLayer<ValueType>, ValueType>
    {
    public:
        using LayerType = predictors::neural::ActivationLayer<ValueType>;
        using BaseType = NeuralNetworkLayerNode<ActivationLayerNode<ValueType>, LayerType, ValueType>;

        /// @name Input and Output Ports
        /// @{
        using BaseType::input;
        using BaseType::output;
        /// @}

        ActivationLayerNode() = default;

        /// <summary> Constructor from a layer. </summary>
        ///
        /// <param name="input"> </param>
        /// <param name="layer"> The layer to wrap. </param>
        ActivationLayerNode(const model::OutputPort<ValueType>& input,
                            const predictors::neural::ActivationLayer<ValueType>& layer);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return utilities::GetCompositeTypeName<ValueType>("ActivationLayerNode"); }

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

    //
    // The ParametricReLUActivationLayerNode
    //

    /// <summary> A node that wraps a neural net parametric ReLU ActivationLayer. </summary>
    template <typename ValueType>
    class ParametricReLUActivationLayerNode
        : public NeuralNetworkLayerNode<ParametricReLUActivationLayerNode<ValueType>,
                                        predictors::neural::ActivationLayer<ValueType>,
                                        ValueType>
    {
    public:
        using LayerType = predictors::neural::ActivationLayer<ValueType>;
        using BaseType = NeuralNetworkLayerNode<ParametricReLUActivationLayerNode<ValueType>, LayerType, ValueType>;

        /// @name Input and Output Ports
        /// @{
        using BaseType::input;
        using BaseType::output;
        /// @}

        ParametricReLUActivationLayerNode() = default;

        /// <summary> Constructor from a layer. </summary>
        ///
        /// <param name="input"> </param>
        /// <param name="layer"> The layer to wrap. </param>
        ParametricReLUActivationLayerNode(const model::OutputPort<ValueType>& input, const LayerType& layer);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName()
        {
            return utilities::GetCompositeTypeName<ValueType>("ParametricReLUActivationLayerNode");
        }

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
