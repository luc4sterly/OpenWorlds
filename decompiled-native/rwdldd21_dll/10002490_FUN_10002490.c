// 10002490 FUN_10002490 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002490(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  
  DAT_10038a90 = *(uint *)(param_1 + 0x10);
  if ((DAT_10038a90 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038a90 >> 1 & DAT_10038a90;
    if (uVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar3 = uVar3 + 1;
      }
    }
  }
  else {
    uVar3 = 0x1f;
  }
  DAT_10038ad0 = *(uint *)(param_2 + 0x10);
  if ((DAT_10038ad0 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038ad0 >> 1 & DAT_10038ad0;
    if (uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar1 = uVar1 + 1;
      }
    }
  }
  else {
    uVar1 = 0x1f;
  }
  if (uVar3 <= uVar1) {
    _DAT_10038a58 = uVar1 - uVar3;
  }
  else {
    _DAT_10038a58 = uVar3 - uVar1;
  }
  DAT_10038b6c = (ushort)(uVar3 <= uVar1);
  DAT_10038a88 = *(uint *)(param_1 + 0x14);
  if ((DAT_10038a88 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038a88 >> 1 & DAT_10038a88;
    if (uVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar3 = uVar3 + 1;
      }
    }
  }
  else {
    uVar3 = 0x1f;
  }
  DAT_10038a18 = *(uint *)(param_2 + 0x14);
  if ((DAT_10038a18 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038a18 >> 1 & DAT_10038a18;
    if (uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar1 = uVar1 + 1;
      }
    }
  }
  else {
    uVar1 = 0x1f;
  }
  if (uVar3 <= uVar1) {
    _DAT_10038b30 = uVar1 - uVar3;
  }
  else {
    _DAT_10038b30 = uVar3 - uVar1;
  }
  DAT_10038b2c = (ushort)(uVar3 <= uVar1);
  DAT_10038af8 = *(uint *)(param_1 + 0x18);
  if ((DAT_10038af8 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038af8 >> 1 & DAT_10038af8;
    if (uVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar3 = uVar3 + 1;
      }
    }
  }
  else {
    uVar3 = 0x1f;
  }
  DAT_10038a54 = *(uint *)(param_2 + 0x18);
  if ((DAT_10038a54 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038a54 >> 1 & DAT_10038a54;
    if (uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar1 = uVar1 + 1;
      }
    }
  }
  else {
    uVar1 = 0x1f;
  }
  if (uVar3 <= uVar1) {
    _DAT_10038afc = uVar1 - uVar3;
  }
  else {
    _DAT_10038afc = uVar3 - uVar1;
  }
  DAT_10038b28 = (ushort)(uVar3 <= uVar1);
  uVar2 = *(uint *)(param_1 + 4) & 1;
  if ((uVar2 == 0) || ((*(uint *)(param_2 + 4) & 1) == 0)) {
    if (uVar2 == 0) {
      DAT_10038b58 = 0;
    }
    else {
      DAT_10038b58 = *(undefined4 *)(param_1 + 0x1c);
    }
    if ((*(uint *)(param_2 + 4) & 1) == 0) {
      DAT_10038b04 = 0;
    }
    else {
      DAT_10038b04 = *(undefined4 *)(param_2 + 0x1c);
    }
    _DAT_10038ad4 = 0;
    _DAT_10038a8c = 1;
    return;
  }
  DAT_10038b58 = *(uint *)(param_1 + 0x1c);
  if ((DAT_10038b58 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038b58 >> 1 & DAT_10038b58;
    if (uVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar3 = uVar3 + 1;
      }
    }
  }
  else {
    uVar3 = 0x1f;
  }
  DAT_10038b04 = *(uint *)(param_2 + 0x1c);
  if ((DAT_10038b04 & 0x80000000) == 0) {
    uVar2 = ~DAT_10038b04 >> 1 & DAT_10038b04;
    if (uVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar1 = uVar1 + 1;
      }
    }
  }
  else {
    uVar1 = 0x1f;
  }
  if (uVar1 < uVar3) {
    _DAT_10038ad4 = uVar3 - uVar1;
    _DAT_10038a8c = 0;
    return;
  }
  _DAT_10038ad4 = uVar1 - uVar3;
  _DAT_10038a8c = 1;
  return;
}


