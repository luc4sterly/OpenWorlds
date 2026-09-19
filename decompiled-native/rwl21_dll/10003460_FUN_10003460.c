// 10003460 FUN_10003460 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_10003460(undefined4 param_1,int param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  undefined4 extraout_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined8 uVar6;
  undefined4 *local_14;
  
  local_14 = (undefined4 *)0x0;
  puVar4 = param_3;
  do {
    if ((0x80000000 < (uint)puVar4[3]) ||
       ((local_14 != (undefined4 *)0x0 && ((float)puVar4[4] <= (float)local_14[4])))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    puVar5 = *(undefined4 **)*puVar4;
    if (bVar3) {
      bVar3 = true;
      do {
        if ((puVar5 == (undefined4 *)0x0) || ((undefined4 *)*puVar5 == puVar4)) break;
        param_2 = puVar5[3];
        bVar3 = 0x3a83126f < param_2;
        if (!bVar3) {
          uVar6 = RwDotProduct((undefined4 *)*puVar5,param_2);
          param_2 = (int)((ulonglong)uVar6 >> 0x20);
          fVar1 = (float)(extraout_ST0 + (float10)(float)puVar4[8]);
          if ((extraout_ST0 + (float10)(float)puVar4[8] < (float10)_DAT_10052070) ||
             (bVar3 = false, 0x3f800000 < (int)fVar1)) {
            bVar3 = true;
          }
          if (!bVar3) {
            uVar6 = RwDotProduct(extraout_ECX,param_2);
            param_2 = (int)((ulonglong)uVar6 >> 0x20);
            fVar2 = (float)(extraout_ST0_00 + (float10)(float)puVar4[0xc]);
            if ((extraout_ST0_00 + (float10)(float)puVar4[0xc] < (float10)_DAT_10052070) ||
               (bVar3 = false, 0x3f800000 < (int)fVar2)) {
              bVar3 = true;
            }
            if ((!bVar3) &&
               ((fVar2 = fVar2 + fVar1, fVar2 < _DAT_10052070 ||
                (bVar3 = false, 0x3f800000 < (int)fVar2)))) {
              bVar3 = true;
            }
          }
        }
        puVar5 = (undefined4 *)*puVar5;
      } while (bVar3);
      if (bVar3) {
        local_14 = puVar4;
      }
    }
    puVar4 = (undefined4 *)*puVar4;
    if (param_3 == puVar4) {
      return CONCAT44(param_2,local_14);
    }
  } while( true );
}


