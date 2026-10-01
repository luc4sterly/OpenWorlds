// 00402b70 FUN_00402b70 [Global]
// program: gamma.dll

void __cdecl FUN_00402b70(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_core_Std_0046d39c);
  iVar2 = FUN_004031c0(param_1,uVar1,s_printlnOut_0046d3c8,s__Ljava_lang_String__V_0046d3b0);
  (**(code **)(*param_1 + 0x29c))(param_1,param_2);
  FUN_00402bd0(param_1,uVar1,iVar2);
  return;
}


