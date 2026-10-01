// 10039990 RwWriteStream [Global]
// program: RWL21.DLL

bool RwWriteStream(int *param_1,undefined4 *param_2,uint param_3)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  
                    /* 0x39990  527  RwWriteStream */
  if (((param_1 == (int *)0x0) || (param_2 == (undefined4 *)0x0)) || (param_3 == 0)) {
    iVar6 = 1;
  }
  else if ((param_1[1] == 2) || (param_1[1] == 3)) {
    iVar6 = *param_1;
    if (0 < iVar6) {
      if (iVar6 < 3) {
        sVar1 = _fwrite(param_2,1,param_3,(FILE *)param_1[2]);
        if (param_3 != sVar1) {
          FUN_1000cba0(0xc);
        }
        return param_3 == sVar1;
      }
      if (iVar6 == 3) {
        piVar4 = param_1 + 2;
        if (param_1[4] == 0) {
          iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x200);
          param_1[4] = iVar6;
          if (iVar6 == 0) {
            FUN_1000cba0(3);
            return false;
          }
          param_1[3] = 0x200;
        }
        iVar6 = param_1[3];
        if ((uint)(iVar6 - *piVar4) < param_3) {
          if (param_3 < 0x200) {
            iVar6 = iVar6 + 0x200;
          }
          else {
            iVar6 = iVar6 + param_3;
          }
          iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x354))(param_1[4],iVar6);
          param_1[3] = iVar6;
          if (iVar2 == 0) {
            FUN_1000cba0(3);
            return false;
          }
          param_1[4] = iVar2;
        }
        puVar5 = (undefined4 *)(*piVar4 + param_1[4]);
        for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = *param_2;
          param_2 = param_2 + 1;
          puVar5 = puVar5 + 1;
        }
        for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar5 = *(undefined1 *)param_2;
          param_2 = (undefined4 *)((int)param_2 + 1);
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
        *piVar4 = *piVar4 + param_3;
        return true;
      }
    }
    iVar6 = 0x57;
  }
  else {
    iVar6 = 0x56;
  }
  FUN_1000cba0(iVar6);
  return false;
}


