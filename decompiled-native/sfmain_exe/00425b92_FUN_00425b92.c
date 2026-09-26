// 00425b92 FUN_00425b92 [Global]
// programa: sfmain.exe

uint __fastcall FUN_00425b92(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  byte *in_EAX;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined1 *unaff_EBX;
  byte local_3c;
  uint local_34;
  byte *local_30;
  byte *local_20;
  uint local_18;
  int local_14;
  
  local_14 = 0;
  local_30 = in_EAX;
  if (param_1 != 0) {
    *in_EAX = 0x80;
    in_EAX[1] = 0xc9;
    in_EAX[2] = 0;
    in_EAX[3] = 1;
    uVar3 = Ordinal_8(param_2);
    *(undefined4 *)(in_EAX + 4) = uVar3;
    local_30 = in_EAX + 8;
    local_14 = 8;
  }
  uVar1 = Ordinal_9(0x81cb);
  *(undefined2 *)local_30 = uVar1;
  uVar3 = Ordinal_8(param_2);
  *(undefined4 *)(local_30 + 4) = uVar3;
  local_20 = local_30 + 8;
  if ((unaff_EBX != (undefined1 *)0x0) && (iVar4 = FUN_0042c5ad(), 0 < iVar4)) {
    local_18._0_1_ = (byte)iVar4;
    *local_20 = (byte)local_18;
    FUN_004080a4(extraout_ECX,unaff_EBX);
    local_20 = local_30 + iVar4 + 9;
  }
  while (((int)local_20 - (int)local_30 & 3U) != 0) {
    *local_20 = 0;
    local_20 = local_20 + 1;
  }
  iVar4 = (int)local_20 - (int)local_30 >> 0x1f;
  uVar1 = Ordinal_9(((int)((((int)local_20 - (int)local_30) + iVar4 * -4) - (uint)(iVar4 << 1 < 0))
                    >> 2) - 1U & 0xffff);
  *(undefined2 *)(local_30 + 2) = uVar1;
  uVar5 = Ordinal_15(*(undefined2 *)(local_30 + 2));
  local_18 = local_14 + (uVar5 & 0xffff) * 4 + 4;
  if (param_1 != 0) {
    local_34 = local_18;
    if ((local_18 & 4) == 0) {
      local_34 = local_18 + 4;
    }
    if (local_18 < local_34) {
      iVar4 = local_34 - local_18;
      FUN_00408098(extraout_ECX_00,0);
      local_3c = (byte)iVar4;
      in_EAX[local_34 - 1] = local_3c;
      *local_30 = *local_30 | 0x20;
      uVar2 = Ordinal_15(*(undefined2 *)(local_30 + 2));
      uVar1 = Ordinal_9(((int)((iVar4 + (iVar4 >> 0x1f) * -4) - (uint)((iVar4 >> 0x1f) << 1 < 0)) >>
                        2) + (uint)uVar2 & 0xffff);
      *(undefined2 *)(local_30 + 2) = uVar1;
      local_18 = local_34;
    }
  }
  return local_18;
}


