// 10026cc0 FUN_10026cc0 [Global]
// programa: RWL21.DLL

int * FUN_10026cc0(char *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  uint local_10;
  char acStack_8 [4];
  char local_4 [4];
  
  piVar2 = FUN_10021350(param_1,param_2);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar5 = (int *)0x0;
  if (param_3 != 0) {
    uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
    puVar3 = FUN_10037030(DAT_1005acdc);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[0xc] = 0;
      puVar3[0xf] = 0;
      puVar3[0xd] = 0;
      puVar3[0xe] = 0;
      puVar3[7] = 0;
      puVar3[8] = 0;
      puVar3[9] = uVar1;
      puVar3[1] = 0;
      iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar3);
      if (iVar4 == 0) {
        FUN_10037010(DAT_1005acdc,puVar3);
        puVar3 = (undefined4 *)0x0;
      }
    }
    if ((puVar3 != (undefined4 *)0x0) &&
       (piVar5 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x48))(piVar2,puVar3,4),
       piVar5 == (int *)0x0)) {
      RwDestroyRaster(puVar3);
    }
    goto LAB_10026f63;
  }
  if (((param_2 & 8) != 0) && ((param_2 & 0x10) == 0)) {
    if (piVar2[0xd] != 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2[0xd]);
      piVar2[0xd] = 0;
      piVar2[0xe] = 0;
    }
    if (((byte)param_2 & 0x28) != 0x28) {
      return piVar2;
    }
    RwGetDeviceInfo(6,local_4,4);
    RwGetDeviceInfo(7,acStack_8,4);
    pcVar6 = (char *)piVar2[6];
    iVar4 = piVar2[10] * piVar2[8];
    while (iVar4 != 0) {
      iVar4 = iVar4 + -1;
      if (*pcVar6 == -1) {
        *pcVar6 = local_4[0];
      }
      else {
        *pcVar6 = acStack_8[0] + '\x01' + *pcVar6;
      }
      pcVar6 = pcVar6 + 1;
    }
    return piVar2;
  }
  local_10 = 0;
  if ((param_2 & 0x10) != 0) {
    local_10 = 2;
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) goto LAB_10026e6c;
  }
  else if ((((param_2 & 4) != 0) &&
           ((*(int *)(PTR_DAT_1005b69c + 0x20) < 0 ||
            ((iVar4 = *(int *)(PTR_DAT_1005b69c + 0x24), iVar4 < 0 &&
             ((int)(0 / (longlong)iVar4) * iVar4 != 0)))))) || (piVar2[9] == 0x18)) {
LAB_10026e6c:
    local_10 = local_10 | 1;
  }
  piVar5 = (int *)0x0;
  uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x14);
  puVar3 = FUN_10037030(DAT_1005acdc);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
LAB_10026ef3:
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[0xc] = 0;
    puVar3[0xf] = 0;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = uVar1;
    puVar3[1] = 0;
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar3);
    if (iVar4 == 0) {
      FUN_10037010(DAT_1005acdc,puVar3);
      goto LAB_10026ef3;
    }
  }
  if (puVar3 != (undefined4 *)0x0) {
    piVar5 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x48))(piVar2,puVar3,local_10);
    if (piVar5 == (int *)0x0) {
      RwDestroyRaster(puVar3);
    }
    else {
      piVar5[0xc] = 0;
    }
  }
  if ((piVar5 != (int *)0x0) && ((param_2 & 0x40) != 0)) {
    if (((piVar5[7] == *(int *)(PTR_DAT_1005b69c + 0x20)) &&
        (*(int *)(PTR_DAT_1005b69c + 0x20) <= piVar5[8])) ||
       ((piVar5[7] == *(int *)(PTR_DAT_1005b69c + 700) &&
        (*(int *)(PTR_DAT_1005b69c + 700) <= piVar5[8])))) {
      puVar3 = FUN_100223e0(piVar2,local_10,(int *)0x0);
      piVar5[0xc] = (int)puVar3;
    }
  }
LAB_10026f63:
  RwDestroyRaster(piVar2);
  return piVar5;
}


