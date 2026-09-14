// 00442750 FUN_00442750 [Global]
// programa: gamma.dll

int __fastcall FUN_00442750(int *param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  uint *this;
  uint uVar5;
  int iVar6;
  uint local_5c;
  ushort *local_54;
  byte local_40 [4];
  byte local_3c;
  byte local_3b;
  ushort uStack_3a;
  ushort local_38;
  byte local_34;
  byte local_33;
  byte abStack_32 [5];
  char local_2d;
  ushort local_2c;
  ushort uStack_2a;
  ushort uStack_26;
  ushort local_24;
  ushort uStack_22;
  short local_20;
  ushort *local_1c;
  int local_18;
  int local_14;
  
  FUN_0042f460((void *)param_1[1],local_40,0x22);
  param_1[0xc] = param_1[0xc] + 0x22;
  if (*(char *)(*(int *)(param_1[1] + 4) + 0x32) == '\0') {
    iVar3 = 0;
  }
  else {
    iVar3 = 2;
  }
  *param_1 = iVar3;
  if (*param_1 != 0) {
    *param_1 = 6;
    return *param_1;
  }
  iVar3 = FUN_0044d760(local_40,&DAT_00479324,4);
  if (iVar3 != 0) {
    *param_1 = 6;
    return *param_1;
  }
  if (((((((char)local_3b < '\0') && ((local_3b >> 4 & 1) == 0)) && ((local_3b >> 2 & 1) == 0)) &&
       (((local_3c >> 5 & 1) == 0 && ((local_3b >> 3 & 1) == 0)))) &&
      (((local_3b >> 6 & 1) == 0 && (((local_3c & 1) == 0 && (local_20 != 0)))))) &&
     (local_2d == '\0')) {
    param_1[2] = (uint)local_38;
    param_1[3] = (uint)uStack_3a;
    param_1[4] = (uint)local_2c;
    if (param_1[4] == 0) {
      param_1[4] = param_1[2];
    }
    param_1[5] = (uint)uStack_2a;
    if (param_1[5] == 0) {
      param_1[5] = param_1[3];
    }
    FUN_00426bc0(&local_1c,(uint)local_24);
    local_54 = local_1c;
    FUN_0042f460((void *)param_1[1],(undefined1 *)local_1c,(uint)local_24);
    param_1[0xc] = param_1[0xc] + (uint)local_24;
    if (*(char *)(*(int *)(param_1[1] + 4) + 0x32) == '\0') {
      iVar3 = 0;
    }
    else {
      iVar3 = 2;
    }
    *param_1 = iVar3;
    if (*param_1 != 0) {
      iVar3 = *param_1;
      FUN_00426c40((int *)&local_1c);
      return iVar3;
    }
    local_5c = (uint)local_34;
    if (local_5c == 0) {
      local_5c = 0x100;
    }
    bVar2 = local_3c >> 1;
    if ((local_3c >> 4 & 1) == 0) {
      iVar3 = FUN_00450b60(local_5c * 4);
      param_1[8] = iVar3;
      param_1[7] = local_5c;
      iVar3 = FUN_004426b0((byte *)local_54,local_5c,(char *)param_1[8]);
      local_54 = (ushort *)((int)local_54 + iVar3);
      if (local_33 != 0) {
        local_54 = (ushort *)((int)local_54 + local_5c + ((int)((uint)local_33 * 0x12 + 7) >> 3));
      }
      if ((bVar2 & 1) == 0) {
        local_54 = (ushort *)((int)local_54 + local_5c);
      }
      if ((local_3b & 1) != 0) {
        local_54 = (ushort *)
                   ((int)local_54 +
                   ((int)((local_5c + 1) - (uint)(local_5c < 0x80000000)) >> 1) + local_5c + -1);
      }
    }
    else {
      FUN_00402800(s_scapeimpl_00479318,0xb6);
    }
    if ((local_3c >> 3 & 1) != 0) {
      local_54 = local_54 + 2;
    }
    param_1[6] = (uint)(local_3c >> 2 & 1);
    param_1[9] = 1;
    if ((char)local_3c < '\0') {
      param_1[9] = (uint)*local_54;
      local_54 = local_54 + 7;
    }
    iVar3 = FUN_00450b60(param_1[9] * 4);
    param_1[10] = iVar3;
    iVar3 = FUN_00450b60(param_1[9] * 4);
    iVar6 = 0;
    param_1[0xb] = iVar3;
    do {
      uVar5 = (uint)abStack_32[iVar6];
      pcVar4 = FUN_00442590(iVar6,0,&local_14);
      if (iVar6 == 4) {
        FUN_0044df50(param_1 + 0x16,(undefined4 *)local_54,uVar5);
        param_1[0x56] = uVar5;
      }
      else {
        this = FUN_0044e010(8);
        if (this != (uint *)0x0) {
          FUN_004269c0(this,(byte *)local_54,uVar5,pcVar4,local_14);
        }
        param_1[iVar6 + 0x11] = (int)this;
        if (param_1[iVar6 + 0x11] == 0) {
          *param_1 = 4;
          iVar3 = *param_1;
          FUN_00426c40((int *)&local_1c);
          return iVar3;
        }
      }
      iVar6 = iVar6 + 1;
      local_54 = (ushort *)((int)local_54 + uVar5);
    } while (iVar6 < 5);
    if ((char)local_3c < '\0') {
      FUN_00426ca0(&local_1c,param_1[9] * 0x14);
      FUN_0042f460((void *)param_1[1],(undefined1 *)local_1c,local_18);
      param_1[0xc] = param_1[0xc] + local_18;
      if (*(char *)(*(int *)(param_1[1] + 4) + 0x32) == '\0') {
        iVar3 = 0;
      }
      else {
        iVar3 = 2;
      }
      *param_1 = iVar3;
      if (*param_1 != 0) {
        iVar3 = *param_1;
        FUN_00426c40((int *)&local_1c);
        return iVar3;
      }
      iVar3 = 0;
      for (iVar6 = 0; iVar6 < param_1[9]; iVar6 = iVar6 + 1) {
        *(undefined4 *)(param_1[10] + iVar6 * 4) = *(undefined4 *)((int)local_1c + iVar3);
        iVar1 = iVar3 + 4;
        iVar3 = iVar3 + 0x14;
        *(uint *)(param_1[0xb] + iVar6 * 4) = (uint)*(ushort *)((int)local_1c + iVar1);
      }
    }
    else {
      *(int *)param_1[10] = param_1[0xc];
      *(uint *)param_1[0xb] = (uint)uStack_22;
    }
    iVar3 = param_1[2];
    iVar6 = FUN_00450b60(200);
    param_1[0xd] = iVar6;
    iVar3 = FUN_00450b60((iVar3 + 3 >> 2) * 2);
    param_1[0xf] = iVar3;
    param_1[0x10] = uStack_26 + 0x402;
    iVar3 = *param_1;
    FUN_00426c40((int *)&local_1c);
    return iVar3;
  }
  *param_1 = 7;
  return *param_1;
}


