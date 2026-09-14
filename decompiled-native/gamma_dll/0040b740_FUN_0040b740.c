// 0040b740 FUN_0040b740 [Global]
// programa: gamma.dll

void __cdecl FUN_0040b740(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_00489180 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_console_Console_0046e710);
    DAT_00489180 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_00489180 == 0) {
      FUN_00402800(s_nConsole_0046e72c,0x20);
    }
    DAT_00489184 = (**(code **)(*param_1 + 0x1c4))
                             (param_1,DAT_00489180,s_println_0046e750,
                              s__Ljava_lang_String__V_0046e738);
    if (DAT_00489184 == 0) {
      FUN_00402800(s_nConsole_0046e72c,0x24);
    }
  }
  (**(code **)(*param_1 + 0x29c))(param_1,param_2);
  FUN_00402bd0(param_1,DAT_00489180,DAT_00489184);
  return;
}


