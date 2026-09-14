// 00454290 FUN_00454290 [Global]
// programa: gamma.dll

void __cdecl FUN_00454290(uint param_1,uint param_2)

{
  *(uint *)(param_1 + 0xc) = param_2 | 3;
  *(undefined4 *)((param_2 - 8) + param_1) = *(undefined4 *)(param_1 + 0xc);
  FUN_00454460((uint *)(param_1 + 0x10),param_2 - 0x18,param_1,0,0);
  *(uint *)(param_1 + 8) = param_2 - 0x18;
  *(undefined4 *)((*(uint *)(param_1 + 0xc) & 0xfffffff8) + param_1 + -4) = 0;
  FUN_00454380(param_1,(uint *)(param_1 + 0x10));
  return;
}


