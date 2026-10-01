// 00432550 FUN_00432550 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00432550(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  float fVar3;
  LPVOID pvVar4;
  float10 fVar5;
  float fStack_70;
  float fStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 auStack_40 [5];
  undefined **ppuStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined **appuStack_1c [4];
  
  param_1[0x1e] = *param_2;
  param_1[0x1f] = param_2[1];
  cVar2 = (**(code **)*param_1)();
  if (cVar2 != '\0') {
    FUN_00427cb0((int *)&uStack_50,param_1 + 0x1e,param_1 + 0x10);
    FUN_00427cb0((int *)&uStack_48,param_1 + 0x12,param_1 + 0x10);
    fStack_70 = (float)(((float10)uStack_50 + (float10)uStack_4c / (float10)DAT_00472020) /
                       ((float10)uStack_48 + (float10)uStack_44 / (float10)DAT_00472020));
    fVar3 = DAT_004751a0;
    if (((byte)(fStack_70 < DAT_004751a0 |
               (byte)((ushort)((ushort)(NAN(fStack_70) || NAN(DAT_004751a0)) << 10) >> 8)) == 1) ||
       (fVar3 = DAT_0047519c,
       (byte)(DAT_0047519c < fStack_70 |
             (byte)((ushort)((ushort)(NAN(DAT_0047519c) || NAN(fStack_70)) << 10) >> 8)) == 1)) {
      fStack_70 = fVar3;
    }
    if (param_1[0x14] == 1) {
      puVar1 = param_1 + 0x2a;
      FUN_004295a0(appuStack_1c,fStack_70,(int)puVar1);
      FUN_00428cd0(&ppuStack_2c,(int)(param_1 + 0x26),(int)appuStack_1c);
      param_1[0x16] = uStack_28;
      param_1[0x17] = uStack_24;
      param_1[0x18] = uStack_20;
      ppuStack_2c = &PTR_LAB_00473390;
      appuStack_1c[0] = &PTR_LAB_004732e8;
      FUN_00429310(auStack_40,(int)(param_1 + 0x2e),(int)(param_1 + 0x33),fStack_70);
      FUN_00428e20(param_1 + 0x19,(int)auStack_40);
      FUN_00428e50(auStack_40);
      fVar5 = FUN_004295e0((int)puVar1,(int)puVar1);
      if (fVar5 < (float10)_DAT_00475190) {
        pvVar4 = FUN_00453ed0();
        *(undefined4 *)((int)pvVar4 + 4) = 0x21;
        fStack_54 = _DAT_004823b0;
      }
      else {
        fStack_54 = SQRT((float)fVar5);
      }
      fStack_54 = fStack_54 * fStack_70;
    }
    else if (param_1[0x14] == 2) {
      FUN_00431a80(param_1 + 0x38,fStack_70,(int)(param_1 + 0x15),param_1 + 0x19,&fStack_54);
    }
    param_1[0x25] = ((float)param_1[6] - (float)param_1[0x24]) * fStack_70 + (float)param_1[0x24];
    param_1[0x20] = fStack_54 - (float)param_1[0x23];
    param_1[0x23] = fStack_54;
  }
  return;
}


