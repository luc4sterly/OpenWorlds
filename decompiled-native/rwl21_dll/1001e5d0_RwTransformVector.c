// 1001e5d0 RwTransformVector [Global]
// program: RWL21.DLL

void RwTransformVector(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
                    /* 0x1e5d0  516  RwTransformVector */
  fVar1 = *param_1;
  fVar2 = param_2[1];
  fVar3 = param_1[1];
  fVar4 = param_2[2];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_1[2];
  *param_1 = param_2[8] * fVar7 + param_2[4] * fVar3 + *param_2 * fVar1;
  param_1[1] = param_2[9] * fVar7 + fVar5 * fVar3 + fVar2 * fVar1;
  param_1[2] = param_2[10] * fVar7 + fVar3 * fVar6 + fVar1 * fVar4;
  return;
}


