// 1001e660 FUN_1001e660 [Global]
// program: RWL21.DLL

float * FUN_1001e660(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float *pfVar4;
  float fVar5;
  float *pfVar6;
  float fVar7;
  float *pfVar8;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  if (*(char *)(param_3 + 0x10) == '\0') {
    RwCrossProduct(param_3,param_3 + 4,local_30);
    RwCrossProduct(param_3 + 4,param_3 + 8,local_c);
    RwCrossProduct(param_3 + 8,param_3,local_18);
    pfVar8 = local_24;
    pfVar2 = local_24;
    fVar7 = param_2[2];
    pfVar6 = local_30;
    fVar5 = param_2[1];
    pfVar4 = local_18;
    pfVar1 = (float *)RwScaleVector(local_c,*param_2,local_24);
    pfVar2 = (float *)FUN_100428a0(pfVar1,pfVar4,fVar5,pfVar2);
    FUN_100428a0(pfVar2,pfVar6,fVar7,pfVar8);
    param_2 = local_24;
  }
  fVar3 = rwLengthNormaliseVector(param_1,param_2);
  if ((int)(float)fVar3 < 1) {
    param_1 = (float *)0x0;
  }
  return param_1;
}


