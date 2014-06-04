//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

namespace grid {
    namespace light {
        class Light {
            public:
                Light(glm::vec3, glm::vec3);
                ~Light();
                void set_position(glm::vec3);
                void set_intensities(glm::vec3);
                glm::vec3 get_position();
                glm::vec3 get_intensities();

            private:
                glm::vec3 position;
                glm::vec3 intensities;
        };
    }
}
