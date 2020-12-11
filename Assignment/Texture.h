#include "glad/glad.h"

#include <string>

    class Texture 
    {
    public:

        Texture(std::string _path);


        GLuint getId();

    private:

        GLuint id;                                                    


    };


