// 004033e2 FUN_004033e2 [Global]
// programa: sfmain.exe

void __fastcall FUN_004033e2(int param_1)

{
  int in_EAX;
  undefined4 extraout_ECX;
  short *extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int extraout_ECX_04;
  undefined4 extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_EDX;
  ushort *unaff_EBX;
  short *psVar1;
  undefined2 auStack_24 [8];
  int local_14;
  
  *(byte *)(in_EAX + 0x26c) = *(byte *)(in_EAX + 0x26c) ^ 1;
  psVar1 = (short *)((*(int *)(in_EAX + 0x26a) >> 0x10) * 0x10 + in_EAX + 0x24c);
  local_14 = param_1;
  FUN_004029f7(param_1,psVar1);
  FUN_00402e8f(extraout_ECX,psVar1);
  FUN_00402fdd();
  FUN_004031c0(unaff_EBX,extraout_EDX,extraout_ECX_00);
  FUN_00402f04(extraout_ECX_01,psVar1);
  FUN_00402fdd();
  FUN_004031c0((ushort *)(extraout_ECX_02 + 0x1a),(int)auStack_24,(short *)(local_14 + 0x1a));
  FUN_00402f4c(extraout_ECX_03,psVar1);
  FUN_00402fdd();
  FUN_004031c0((ushort *)(extraout_ECX_04 + 0x36),(int)auStack_24,(short *)(local_14 + 0x36));
  FUN_00402fc1(extraout_ECX_05,auStack_24);
  FUN_00402fdd();
  FUN_004031c0((ushort *)(extraout_ECX_06 + 0x50),(int)auStack_24,(short *)(local_14 + 0x50));
  return;
}


