// 00407981 FUN_00407981 [Global]
// programa: sfmain.exe

void __fastcall FUN_00407981(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int in_EAX;
  undefined2 *puVar3;
  undefined4 extraout_ECX;
  int iVar4;
  short *unaff_EBX;
  ushort *in_stack_00000010;
  undefined2 auStack_1ac [160];
  short local_6c [40];
  undefined4 local_1c;
  undefined2 *local_18;
  undefined2 *local_14;
  int local_10;
  
  local_14 = (undefined2 *)(in_EAX + 0xf0);
  local_18 = (undefined2 *)(in_EAX + 0x140);
  local_10 = 0;
  local_1c = param_2;
  do {
    FUN_00403d37();
    FUN_00405459(local_6c,*unaff_EBX,local_14);
    puVar2 = local_18;
    puVar3 = local_14;
    iVar4 = local_10;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      *(undefined2 *)((int)auStack_1ac + iVar4) = uVar1;
      iVar4 = iVar4 + 2;
    } while (puVar3 != puVar2);
    unaff_EBX = unaff_EBX + 1;
    local_10 = local_10 + 0x50;
  } while (local_10 != 0x140);
  FUN_004033e2((int)in_stack_00000010);
  FUN_004078f8(extraout_ECX,in_stack_00000010);
  return;
}


