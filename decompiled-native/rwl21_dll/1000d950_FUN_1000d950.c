// 1000d950 FUN_1000d950 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_1000d950(float param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  float extraout_ECX;
  float extraout_EDX;
  float10 extraout_ST0;
  float10 fVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  for (puVar4 = DAT_1005a0b0; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    if (puVar4[1] != 2) {
      fVar1 = -(float)puVar4[10];
      fVar2 = -(float)puVar4[0xb];
      fVar3 = -(float)puVar4[0xc];
      local_c = *param_3 * fVar1 + param_3[4] * fVar2 + param_3[8] * fVar3;
      local_8 = param_3[1] * fVar1 + param_3[5] * fVar2 + param_3[9] * fVar3;
      local_4 = fVar3 * param_3[10] + param_3[6] * fVar2 + param_3[2] * fVar1;
      rwLengthNormaliseVector(&local_c,&local_c);
      puVar4[0x16] = local_c;
      puVar4[0x17] = local_8;
      puVar4[0x18] = local_4;
      param_1 = local_c;
      param_2 = local_8;
    }
    if (puVar4[1] != 1) {
      fVar1 = (float)puVar4[0xe];
      fVar2 = (float)puVar4[0xf];
      fVar3 = (float)puVar4[0x10];
      puVar4[0x13] = *param_3 * fVar1 + param_3[4] * fVar2 + param_3[8] * fVar3 + param_3[0xc];
      puVar4[0x14] = param_3[1] * fVar1 + param_3[5] * fVar2 + param_3[9] * fVar3 + param_3[0xd];
      puVar4[0x15] = fVar3 * param_3[10] + param_3[6] * fVar2 + param_3[2] * fVar1 + param_3[0xe];
      RwDotProduct(param_1,param_2);
      local_10 = (float)extraout_ST0;
      fVar5 = FUN_10041770((int *)&local_10);
      local_10 = (float)(fVar5 * (float10)(float)puVar4[0x19]);
      puVar4[0x1a] = (float)(fVar5 * (float10)(float)puVar4[0x19]);
      local_10 = local_10 * local_10;
      puVar4[0x1b] = local_10;
      local_10 = local_10 * _DAT_100520f0;
      puVar4[0x1c] = local_10;
      param_1 = extraout_ECX;
      param_2 = extraout_EDX;
    }
  }
  return;
}


