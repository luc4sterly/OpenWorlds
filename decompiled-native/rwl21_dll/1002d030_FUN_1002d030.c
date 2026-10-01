// 1002d030 FUN_1002d030 [Global]
// program: RWL21.DLL

int __fastcall FUN_1002d030(float param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  float extraout_ECX;
  float extraout_ECX_00;
  float extraout_ECX_01;
  undefined4 extraout_ECX_02;
  float extraout_ECX_03;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 *puVar6;
  int iVar7;
  undefined8 uVar8;
  uint local_4;
  
  if (param_3 != (uint *)0x0) {
    if (((*param_3 & 4) == 0) || (local_4 = param_3[4], local_4 == 0)) {
      local_4 = 0;
    }
    uVar1 = param_3[0x11];
    if (uVar1 == 1) {
      param_1 = ((float *)param_3[0x12])[0x5d];
      if (param_1 == 0.0) {
        FUN_10008eb0(0,param_2,(float *)param_3[0x12]);
        param_1 = extraout_ECX;
        param_2 = extraout_EDX;
      }
      param_4 = param_4 + 1;
    }
    else if (uVar1 == 2) {
      uVar1 = param_3[0x12];
      puVar6 = (undefined4 *)param_3[0x13];
      uVar8 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(uVar1 * 4);
      iVar5 = (int)uVar8;
      if (iVar5 == 0) {
        FUN_1000cba0(3);
        param_1 = extraout_ECX_00;
        param_2 = extraout_EDX_00;
      }
      else {
        iVar7 = uVar1 - 1;
        if (-1 < iVar7) {
          puVar4 = (undefined4 *)(iVar5 + iVar7 * 4);
          do {
            uVar2 = *puVar6;
            puVar6 = puVar6 + 1;
            *puVar4 = uVar2;
            puVar4 = puVar4 + -1;
            iVar7 = iVar7 + -1;
          } while (-1 < iVar7);
        }
        uVar1 = param_3[0x12];
        while( true ) {
          uVar1 = uVar1 - 1;
          if ((int)uVar1 < 0) break;
          uVar2 = *(undefined4 *)uVar8;
          param_4 = FUN_1002d030((float)uVar2,(int)((ulonglong)uVar8 >> 0x20),(uint *)uVar2,param_4)
          ;
          uVar8 = CONCAT44(extraout_EDX_01,(undefined4 *)uVar8 + 1);
        }
        (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar5);
        param_1 = extraout_ECX_01;
        param_2 = extraout_EDX_02;
      }
    }
    else if (uVar1 == 3) {
      puVar3 = (uint *)param_3[0x19];
      iVar5 = FUN_1002d030(param_1,param_2,(uint *)param_3[0x18],param_4);
      param_4 = FUN_1002d030((float)extraout_ECX_02,extraout_EDX_03,puVar3,iVar5);
      param_1 = extraout_ECX_03;
      param_2 = extraout_EDX_04;
    }
    if (local_4 != 0) {
      param_4 = FUN_1002d030(param_1,param_2,(uint *)param_3[4],param_4);
    }
  }
  return param_4;
}


