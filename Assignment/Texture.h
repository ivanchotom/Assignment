#include "glad/glad.h"

#include <string>

    class Texture 
    {
    public:

        Texture(std::string _path, std::string _type );


        GLuint getId();
        
        std::string GetPath();
        std::string GetType();
        std::string path;
        std::string type;
    private:

        GLuint id;                                                    
        

    };


