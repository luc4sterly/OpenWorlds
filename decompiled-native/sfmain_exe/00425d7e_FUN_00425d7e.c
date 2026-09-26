// 00425d7e FUN_00425d7e [Global]
// programa: sfmain.exe

int __fastcall FUN_00425d7e(undefined2 param_1,undefined4 param_2,int param_3)

{
  byte *in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 unaff_EBX;
  int local_3fa0;
  undefined1 *local_3f9c;
  byte *local_3f98;
  ushort local_3f90;
  undefined2 local_3f8c;
  undefined2 local_3f8a;
  undefined4 local_3f88;
  undefined4 local_3f84;
  undefined1 local_3f80 [3];
  undefined1 local_3f7d;
  byte *local_28;
  int local_20;
  
  if (param_3 == 0) {
    local_3f90 = 0;
  }
  else {
    local_3f90 = 0x80;
  }
  local_28 = in_EAX;
  local_3f8c = Ordinal_9(local_3f90 | 0x8000);
  local_3f8a = Ordinal_9(param_1);
  local_3f88 = Ordinal_8(unaff_EBX);
  local_3f84 = Ordinal_8(param_2);
  if ((*local_28 & 0x20) == 0) {
    if ((local_28[1] & 2) == 0) {
      if ((local_28[1] & 0x10) == 0) {
        FUN_004080a4(extraout_ECX,local_28 + 0x1c);
        local_20 = *(int *)(local_28 + 0x14) + 0xc;
        uVar2 = extraout_ECX_05;
      }
      else {
        iVar1 = (*(int *)(local_28 + 0x14) + -2) / 0xe;
        local_3f98 = local_28 + 0x1e;
        local_3f9c = local_3f80;
        local_3f8c = CONCAT11(7,(undefined1)local_3f8c);
        uVar2 = extraout_ECX;
        for (local_3fa0 = 0; local_3fa0 < iVar1; local_3fa0 = local_3fa0 + 1) {
          FUN_004080a4(uVar2,local_3f98);
          FUN_004080a4(extraout_ECX_03,local_3f98 + 4);
          local_3f9c[0xd] = 0;
          local_3f98 = local_3f98 + 0xe;
          local_3f9c = local_3f9c + 0xe;
          uVar2 = extraout_ECX_04;
        }
        local_20 = iVar1 * 0xe + 0xc;
      }
    }
    else {
      local_3f8c = CONCAT11(5,(undefined1)local_3f8c);
      FUN_004080a4(extraout_ECX,local_28 + 0x1c);
      FUN_004080a4(extraout_ECX_01,local_28 + *(int *)(local_28 + 0x14) + 0x19);
      local_3f7d = 0;
      local_20 = *(int *)(local_28 + 0x14) + 0xd;
      uVar2 = extraout_ECX_02;
    }
  }
  else {
    local_3f8c = CONCAT11(3,(undefined1)local_3f8c);
    FUN_004080a4(extraout_ECX,local_28 + 0x1e);
    local_20 = *(int *)(local_28 + 0x14) + 10;
    uVar2 = extraout_ECX_00;
  }
  if (0 < local_20) {
    FUN_004080a4(uVar2,(undefined1 *)&local_3f8c);
  }
  return local_20;
}


