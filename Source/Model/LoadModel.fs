#version 330 core
out vec4 FragColor;

struct Material  {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

#define NR_POINT_LIGHTS 2

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;


uniform Material material;
uniform Light light[NR_POINT_LIGHTS];
uniform vec3 viewPos;


vec3 CalcPointLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{    
   // 属性
   vec3 norm=normalize(Normal);
   vec3 viewDir=normalize(viewPos-FragPos);
   vec3 result=vec3(0.0,0.0,0.0);
   for(int i = 0; i < NR_POINT_LIGHTS; i++)
   {
      result += CalcPointLight(light[i], norm, FragPos, viewDir);
   }
  
   //FragColor = texture(material.texture_diffuse1, TexCoords);
   FragColor = vec4(result, 1.0);
}

vec3 CalcPointLight(Light light, vec3 normal, vec3 fragPos, vec3 viewDir)
{

  vec3 lightDir = normalize(light.position-fragPos);

   // 漫反射着色
   float diff = max(dot(normal,lightDir),0.0);

   // 镜面光着色
   vec3 reflectDir = reflect(-lightDir,normal);
   float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);

   // 衰减
   float distance    = length(light.position - FragPos);
   float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));  

   vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, TexCoords));
   vec3 diffuse = light.diffuse * diff * vec3(texture(material.texture_diffuse1, TexCoords));
   vec3 specular =  light.specular * spec * vec3(texture(material.texture_specular1, TexCoords));
   ambient  *= attenuation; 
   diffuse  *= attenuation;
   specular *= attenuation; 

   return (ambient+diffuse+specular);
}