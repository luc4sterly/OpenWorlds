// 00406f1a FUN_00406f1a [Global]
// program: gdkup.exe

undefined4 __fastcall FUN_00406f1a(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  short in_AX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_EBX;
  uint *puVar6;
  undefined4 uVar7;
  uint unaff_ESI;
  short in_DS;
  
  uVar3 = unaff_EBX + 7 & 0xfffffffc;
  if (uVar3 < unaff_EBX) {
    uVar3 = 0xffffffff;
  }
  if (uVar3 < 0xc) {
    uVar3 = 0xc;
  }
  puVar1 = (uint *)(param_2 - 4);
  uVar5 = *puVar1 & 0xfffffffe;
  if (uVar5 < uVar3) {
    uVar3 = uVar3 - uVar5;
    puVar6 = (uint *)((int)puVar1 + uVar5);
    while( true ) {
      *param_1 = uVar3;
      uVar5 = *puVar6;
      if (uVar5 == 0xffffffff) break;
      if ((uVar5 & 1) != 0) {
        return 1;
      }
      uVar3 = puVar6[2];
      uVar2 = puVar6[1];
      uVar4 = DAT_00408b28;
      if (in_DS == in_AX) {
        for (; (unaff_ESI = uVar4, *(uint *)(uVar4 + 8) != 0 &&
               ((param_2 < uVar4 || (*(uint *)(uVar4 + 8) <= param_2))));
            uVar4 = *(uint *)(uVar4 + 8)) {
        }
      }
      if (puVar6 == *(uint **)(unaff_ESI + 0xc)) {
        *(uint *)(unaff_ESI + 0xc) = (*(uint **)(unaff_ESI + 0xc))[1];
      }
      if (*param_1 <= uVar5) {
        uVar4 = uVar5 - *param_1;
        if (0xb < uVar4) {
          puVar6 = (uint *)((int)puVar6 + *param_1);
          *puVar6 = uVar4;
          puVar6[1] = uVar2;
          puVar6[2] = uVar3;
          *(uint **)(uVar2 + 8) = puVar6;
          *(uint **)(uVar3 + 4) = puVar6;
          *puVar1 = *puVar1 + *param_1;
          DAT_0040b46d = 0;
          return 0;
        }
      }
      *(uint *)(uVar2 + 8) = uVar3;
      *(uint *)(uVar3 + 4) = uVar2;
      *puVar1 = *puVar1 + uVar5;
      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
      DAT_0040b46d = 0;
      if (*param_1 <= uVar5) goto LAB_0040709e;
      uVar3 = *param_1 - uVar5;
      puVar6 = (uint *)((int)puVar6 + uVar5);
    }
    uVar7 = 2;
  }
  else {
    if (0xb < uVar5 - uVar3) {
      *puVar1 = uVar3 | 1;
      *(uint *)((int)puVar1 + uVar3) = uVar5 - uVar3 | 1;
      uVar3 = DAT_00408b28;
      if (in_DS == in_AX) {
        for (; (unaff_ESI = uVar3, *(uint *)(uVar3 + 8) != 0 &&
               ((param_2 < uVar3 || (*(uint *)(uVar3 + 8) <= param_2))));
            uVar3 = *(uint *)(uVar3 + 8)) {
        }
      }
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + 1;
      FUN_00403235();
    }
LAB_0040709e:
    uVar7 = 0;
  }
  return uVar7;
}


