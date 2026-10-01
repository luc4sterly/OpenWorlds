// 004032fc FUN_004032fc [Global]
// program: sfmain.exe

void __fastcall FUN_004032fc(undefined4 param_1)

{
  int in_EAX;
  ushort *extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  short *extraout_EDX;
  short *extraout_EDX_00;
  short *extraout_EDX_01;
  short *extraout_EDX_02;
  undefined4 unaff_EBX;
  short *psVar1;
  undefined2 auStack_24 [8];
  
  *(byte *)(in_EAX + 0x26c) = *(byte *)(in_EAX + 0x26c) ^ 1;
  psVar1 = (short *)((*(int *)(in_EAX + 0x26a) >> 0x10) * 0x10 + in_EAX + 0x24c);
  FUN_004029f7(param_1,psVar1);
  FUN_00402e8f(unaff_EBX,psVar1);
  FUN_00402fdd();
  FUN_004030c4(extraout_ECX,extraout_EDX);
  FUN_00402f04(unaff_EBX,psVar1);
  FUN_00402fdd();
  FUN_004030c4((ushort *)(extraout_ECX_00 + 0x1a),extraout_EDX_00);
  FUN_00402f4c(unaff_EBX,psVar1);
  FUN_00402fdd();
  FUN_004030c4((ushort *)(extraout_ECX_01 + 0x36),extraout_EDX_01);
  FUN_00402fc1(unaff_EBX,auStack_24);
  FUN_00402fdd();
  FUN_004030c4((ushort *)(extraout_ECX_02 + 0x50),extraout_EDX_02);
  return;
}


