// 00401000 _Java_NET_worlds_core_IniFile_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_core_IniFile_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x1000  137  _Java_NET_worlds_core_IniFile_nativeInit@8 */
  if (DAT_00489000 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_core_IniFile_0046d000);
    DAT_00489000 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489000 == 0) {
      FUN_00402800(s_nIniFile_0046d018,0x24);
    }
    DAT_00489008 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489000,&DAT_0046d038,s_Ljava_lang_String__0046d024);
    DAT_00489004 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489000,s_section_0046d040,s_Ljava_lang_String__0046d024)
    ;
    bVar1 = false;
    if ((DAT_00489004 != 0) && (DAT_00489008 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nIniFile_0046d018,0x2a);
    }
  }
  return;
}


