#include "glad/glad.h"

#include <string>

    class Texture 
    {
    public:

        Texture(std::string _path, std::string _type );


        unsigned int getId();
        void setId(unsigned int idset) { id = idset; }
        std::string GetPath();
        std::string GetType();
        std::string path;
        std::string textype;
        unsigned int idset;
    private:


        
        unsigned int id; 
       
        

    };


