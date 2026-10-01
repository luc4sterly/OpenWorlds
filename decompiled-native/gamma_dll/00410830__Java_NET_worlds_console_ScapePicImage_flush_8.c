// 00410830 _Java_NET_worlds_console_ScapePicImage_flush@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_ScapePicImage_flush_8(int *param_1,undefined4 param_2)

{
  HGDIOBJ ho;
  
                    /* 0x10830  65  _Java_NET_worlds_console_ScapePicImage_flush@8 */
  ho = (HGDIOBJ)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489364);
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489364,0);
  }
  return;
}


