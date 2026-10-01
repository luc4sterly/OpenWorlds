// 00423b40 _Java_NET_worlds_scape_ImageConverter_cleanup@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_ImageConverter_cleanup_8(int *param_1,undefined4 param_2)

{
  HGDIOBJ ho;
  
                    /* 0x23b40  235  _Java_NET_worlds_scape_ImageConverter_cleanup@8 */
  ho = (HGDIOBJ)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d1a4);
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
  }
  return;
}


