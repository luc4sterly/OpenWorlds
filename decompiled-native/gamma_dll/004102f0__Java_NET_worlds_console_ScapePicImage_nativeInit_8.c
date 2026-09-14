// 004102f0 _Java_NET_worlds_console_ScapePicImage_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_ScapePicImage_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x102f0  67  _Java_NET_worlds_console_ScapePicImage_nativeInit@8 */
  if (DAT_00489360 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_console_ScapePicImage_0046f060);
    DAT_00489360 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_00489360 == 0) {
      FUN_00402800(s_nScapePicImage_0046f084,0x28);
    }
    DAT_00489364 = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489360,&DAT_0046f098,&DAT_0046f094)
    ;
    DAT_00489368 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489360,s_width_0046f0a0,&DAT_0046f094);
    DAT_0048936c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489360,s_height_0046f0a8,&DAT_0046f094);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_00489364 != 0) && (DAT_00489368 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0048936c != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nScapePicImage_0046f084,0x2d);
    }
  }
  return;
}


