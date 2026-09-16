// 00440da0 FUN_00440da0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00440da0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 0x44);
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(iVar1 + 0x34);
  uVar2 = *(uint *)(iVar1 + 0x38);
  uVar3 = (int)uVar2 >> 0x1f;
  *(uint *)(param_1 + 0x138) = (uVar2 ^ uVar3) - uVar3;
  FUN_0044d5a0(s_Source_video_is__d_x__d_004782e0);
  *(uint *)(param_1 + 0x13c) = *(int *)(param_1 + 0x134) * 3 + 3U & 0xfffffffc;
  return 0;
}


