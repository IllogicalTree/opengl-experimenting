#pragma once
#include <string>
#include <unordered_map>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
    private:
        std::string m_FilePath;
        unsigned int m_RendererId;
        std::unordered_map<std::string, int> m_UniformLocationCache;

        int GetUniformLocation(const std::string& name);
        ShaderProgramSource ParseShader(const std::string& filepath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

    public:
        Shader(const std::string& filename);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
        void SetUniform1i(const std::string& name, int value);
};
