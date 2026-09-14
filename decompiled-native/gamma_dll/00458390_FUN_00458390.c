// 00458390 FUN_00458390 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00458390(undefined4 param_1,int param_2,uint param_3,char *param_4)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  float10 fVar5;
  byte bStack_27;
  undefined1 local_26 [14];
  undefined2 local_18;
  int local_14;
  uint local_10;
  int iVar4;
  
  local_18 = 0x37f;
  puVar2 = (ushort *)(param_4 + 5);
  *param_4 = (char)((int)param_3 >> 0x1f);
  local_14 = param_2;
  local_10 = param_3;
  if ((param_3 & 0x7ff00000) == 0) {
    if (((param_3 & 0xfffff) == 0) && (param_2 == 0)) {
      uVar1 = 3;
    }
    else {
      uVar1 = 5;
    }
  }
  else if ((param_3 & 0x7ff00000) == 0x7ff00000) {
    if (((param_3 & 0xfffff) == 0) && (param_2 == 0)) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 4;
  }
  switch(uVar1) {
  case 1:
    param_4[5] = 'N';
    param_4[4] = '\x01';
    return;
  case 2:
    param_4[5] = 'I';
    param_4[4] = '\x01';
    return;
  case 3:
    param_4[5] = '0';
    param_4[4] = '\x01';
    return;
  case 4:
  case 5:
    DAT_0049eb70 = 1;
    extract_significand(ABS((float10)(double)CONCAT44(param_3,param_2)));
    fVar5 = (float10)extract_exponent(ABS((float10)(double)CONCAT44(param_3,param_2)));
    *(short *)(param_4 + 2) =
         (short)ROUND((float10)0.3010299956639812 * fVar5 - (float10)_DAT_0048300c);
    local_26._6_4_ = 0x458492;
    fVar5 = FUN_00458260();
    if (fVar5 < (float10)_DAT_00483010) {
      fVar5 = fVar5 * (float10)_DAT_00483018;
      *(short *)(param_4 + 2) = *(short *)(param_4 + 2) + -1;
    }
    local_26._0_10_ = to_bcd(fVar5);
    iVar4 = 9;
    do {
      iVar3 = iVar4 + -1;
      *puVar2 = CONCAT11(local_26[iVar4 + -1],(byte)local_26[iVar4 + -1] >> 4) & 0xf0f | 0x3030;
      puVar2 = puVar2 + 1;
      iVar4 = iVar3;
    } while ((short)iVar3 != 0);
  }
  param_4[4] = '\x12';
  return;
}


