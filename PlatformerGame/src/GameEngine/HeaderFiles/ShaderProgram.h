#include <string>
#include <string>


class ShaderProgram {
//vars

private:
	int program, vs, fs;
	const int vsnotCompiled = 8;
	const int fsnotCompiled = 9;


public:


//functions
private:
	std::string LoadShader(std::string path);
	
public:
	ShaderProgram(std::string& filename);
	void Bind();
	void UnBind();
	int makeLocation(const char  name[]);
	void loadInt(int location,int value);
	void loadFloat(int location, float value);
	void loadVec2(int location, float x, float y);
	void loadvec4(int location,float x,float y,float z,float w);

};