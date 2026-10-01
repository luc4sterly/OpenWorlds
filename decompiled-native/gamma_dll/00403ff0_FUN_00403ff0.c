// 00403ff0 FUN_00403ff0 [Global]
// program: gamma.dll

void __cdecl FUN_00403ff0(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (DAT_00489068 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_core_Archive_0046d538);
    DAT_00489068 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489068 == 0) {
      FUN_00402800(s_Archive_0046d550,0x14);
    }
    DAT_0048906c = (**(code **)(*param_1 + 0x1c4))
                             (param_1,DAT_00489068,s_readTextFile_0046d570,
                              s__Ljava_lang_String___B_0046d558);
    DAT_00489070 = (**(code **)(*param_1 + 0x1c4))
                             (param_1,DAT_00489068,s_readBinaryFile_0046d580,
                              s__Ljava_lang_String___B_0046d558);
    bVar1 = false;
    if ((DAT_0048906c != 0) && (DAT_00489070 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_Archive_0046d550,0x1a);
    }
  }
  FUN_00403f80(param_1,DAT_00489068,DAT_00489070);
  return;
}


