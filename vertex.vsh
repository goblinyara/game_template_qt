attribute highp vec4 qt_Vertex;
attribute highp vec3 qt_Normal;
//attribute highp vec4 qt_MultiTexCoord0;
uniform highp mat4 qt_ProjectionMatrix;
uniform highp mat4 qt_WorldMatrix;
uniform highp mat4 qt_ViewMatrix;
uniform highp mat4 qt_ModelRotationMatrix;
//varying highp vec4 qt_TexCoord0;
varying highp vec4 vertex_;
varying highp vec3 normal_;
varying highp vec3 uv_;
void main(void) {
    gl_Position = qt_ProjectionMatrix * qt_ViewMatrix * qt_ModelRotationMatrix * qt_WorldMatrix * qt_Vertex;
    //qt_TexCoord0 = qt_MultiTexCoord0;
    vertex_.x = gl_Position.x;
    vertex_.y = gl_Position.y;
    vertex_.z = gl_Position.z;
    // calculate the normals after rotation
    vec4 normals = qt_ModelRotationMatrix * vec4(qt_Normal, 1.0);
    normal_ = normals.xyz;
}
