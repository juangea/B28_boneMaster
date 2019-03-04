#pragma once

#include "FN_core.hpp"
#include "compile.hpp"

namespace llvm {
	class ExecutionEngine;
	class Module;
	class LLVMContext;
	class FunctionType;
}

namespace FN {

	class LLVMCompiledBody : public FunctionBody {
	private:
		std::unique_ptr<CompiledLLVM> m_compiled;

		LLVMCompiledBody() = default;

	public:
		static const char *identifier_in_composition();
		static void free_self(void *value);

		LLVMCompiledBody(std::unique_ptr<CompiledLLVM> compiled)
			: m_compiled(std::move(compiled)) {}

		void *function_ptr()
		{
			return m_compiled->function_ptr();
		}
	};

	void derive_CompiledLLVMBody_from_LLVMBuildIRBody(
		SharedFunction &fn,
		llvm::LLVMContext &context);

} /* namespace FN */