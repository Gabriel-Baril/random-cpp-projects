#version 440

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;

out vec4 fs_color;

int main()
{
	fs_color = vec4(vs_color, 1.f);
}