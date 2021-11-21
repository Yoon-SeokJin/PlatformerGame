#pragma once
#include <tuple>
#include <string>
#include <string_view>
#include <fstream>

#pragma pack(push, 1)                // ����ü�� 1����Ʈ ũ��� ����

struct BitmapFileHeader     // BMP ��Ʈ�� ���� ��� ����ü
{
    unsigned short type;           // BMP ���� ���� �ѹ�
    unsigned int   size;           // ���� ũ��
    unsigned short reserved1;      // ����
    unsigned short reserved2;      // ����
    unsigned int   offBits;        // ��Ʈ�� �������� ���� ��ġ
};

struct BitmapInfoHeader     // BMP ��Ʈ�� ���� ��� ����ü(DIB ���)
{
    unsigned int   size;           // ���� ����ü�� ũ��
    int            width;          // ��Ʈ�� �̹����� ���� ũ��
    int            height;         // ��Ʈ�� �̹����� ���� ũ��
    unsigned short planes;         // ����ϴ� �������� ��
    unsigned short bit_count;       // �ȼ� �ϳ��� ǥ���ϴ� ��Ʈ ��
    unsigned int   compression;    // ���� ���
    unsigned int   size_image;     // ��Ʈ�� �̹����� �ȼ� ������ ũ��
    int            x_pels_per_meter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    int            y_pels_per_meter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    unsigned int   clr_used;        // ���� ���̺��� ���� ���Ǵ� ���� ��
    unsigned int   clr_important;   // ��Ʈ���� ǥ���ϱ� ���� �ʿ��� ���� �ε��� ��
};

struct RGB            // 24��Ʈ ��Ʈ�� �̹����� �ȼ� ����ü
{
    unsigned char b;          // �Ķ�
    unsigned char g;         // �ʷ�
    unsigned char r;           // ����
};

#pragma pack(pop)

class SpriteImporter {
public:
    bool read_bmp24(std::string_view file_path);
    std::tuple<int*, int, int, int> get();
private:
    int* spr = NULL;
    int w = 0, h = 0, n = 0;
};