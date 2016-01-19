//uniform sampler2D qt_Texture0;
///varying highp vec4 qt_TexCoord0;
varying highp vec4 vertex_;
varying highp vec3 normal_;
uniform vec3 diffuse_;
uniform vec3 ambient_;
uniform vec3 specular_;
uniform float specular_intensity;
void main() {
  vec3 ndotl = vec3(-dot( normal_, vec3(-1) ));
  gl_FragColor = vec4(ambient_ + diffuse_* ndotl, 1.0);///texture2D(qt_Texture0, qt_TexCoord0.st);
}
