// 004020fd FUN_004020fd [Global]
// programa: sfmain.exe

void __fastcall FUN_004020fd(undefined4 param_1,int param_2)

{
  uint uVar1;
  int in_EAX;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  uint unaff_EBX;
  uint uVar2;
  
  uVar1 = *(uint *)(in_EAX + 0x10);
  uVar2 = uVar1 + unaff_EBX * 8;
  *(uint *)(in_EAX + 0x10) = uVar2;
  if (uVar2 < uVar1) {
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
  }
  *(uint *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + (unaff_EBX >> 0x1d);
  uVar2 = uVar1 >> 3 & 0x3f;
  if (uVar2 != 0) {
    uVar2 = 0x40 - uVar2;
    if (unaff_EBX < uVar2) goto LAB_00402193;
    FUN_004080a4(param_2,(undefined1 *)param_2);
    unaff_EBX = unaff_EBX - uVar2;
    FUN_00402223(extraout_ECX,(int *)(in_EAX + 0x18));
    param_2 = extraout_ECX_00 + uVar2;
  }
  for (; 0x3f < unaff_EBX; unaff_EBX = unaff_EBX - 0x40) {
    FUN_004080a4(param_2,(undefined1 *)param_2);
    FUN_00402223(extraout_ECX_01,(int *)(in_EAX + 0x18));
    param_2 = extraout_ECX_02 + 0x40;
  }
LAB_00402193:
  FUN_004080a4(param_2,(undefined1 *)param_2);
  return;
}


