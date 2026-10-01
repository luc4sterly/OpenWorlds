// 1005118c FUN_1005118c [Global]
// program: RWL21.DLL

undefined8 __fastcall
FUN_1005118c(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined4 in_EAX;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  
  iVar16 = 3;
  do {
    pfVar17 = param_5;
    pfVar15 = param_3;
    fVar1 = *pfVar15;
    fVar2 = param_4[1];
    fVar3 = pfVar15[1];
    fVar4 = param_4[5];
    fVar5 = pfVar15[2];
    fVar6 = param_4[9];
    fVar7 = *pfVar15;
    fVar8 = param_4[2];
    fVar9 = pfVar15[1];
    fVar10 = param_4[6];
    fVar11 = pfVar15[2];
    fVar12 = param_4[10];
    *pfVar17 = pfVar15[2] * param_4[8] + pfVar15[1] * param_4[4] + *pfVar15 * *param_4;
    pfVar17[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
    param_3 = pfVar15 + 4;
    iVar16 = iVar16 + -1;
    pfVar17[2] = fVar7 * fVar8 + fVar9 * fVar10 + fVar11 * fVar12;
    param_5 = pfVar17 + 4;
  } while (iVar16 != 0);
  fVar1 = *param_3;
  fVar2 = param_4[1];
  fVar3 = pfVar15[5];
  fVar4 = param_4[0xd];
  fVar5 = param_4[5];
  fVar6 = pfVar15[6];
  fVar7 = param_4[9];
  fVar8 = *param_3;
  fVar9 = param_4[2];
  fVar10 = pfVar15[5];
  fVar11 = param_4[0xe];
  fVar12 = param_4[6];
  fVar13 = pfVar15[6];
  fVar14 = param_4[10];
  pfVar17[4] = pfVar15[6] * param_4[8] + pfVar15[5] * param_4[4] +
               *param_3 * *param_4 + param_4[0xc];
  pfVar17[5] = fVar6 * fVar7 + fVar3 * fVar5 + fVar1 * fVar2 + fVar4;
  pfVar17[6] = fVar8 * fVar9 + fVar11 + fVar10 * fVar12 + fVar13 * fVar14;
  return CONCAT44(param_2,in_EAX);
}


