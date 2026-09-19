// 10035db0 FUN_10035db0 [Global]
// programa: RWL21.DLL

int FUN_10035db0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int iStack_a0;
  int iStack_9c;
  float local_44 [17];
  
  iVar1 = *(int *)(param_1 + 0xe4);
  do {
    if (iVar1 == 0) {
      return param_1;
    }
    if (*(int *)(iVar1 + 0x3c) != 0) {
      FUN_1000cba0(0x62);
      return 0;
    }
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x14);
    switch(*(undefined4 *)(iVar1 + 0x28)) {
    case 1:
      FUN_1001c440(param_3 + 0xbc,param_1,(float *)param_1,param_3 + 0xbc,local_44);
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      (**(code **)(PTR_DAT_1005b69c + 0x294))(&local_b8,1,local_44,param_3,1);
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 8) + (iStack_a0 >> 0x10);
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0xc) + (iStack_9c >> 0x10);
      goto LAB_1003601a;
    case 2:
      FUN_10032550(param_1,*(int *)(iVar1 + 0x30),&local_c0,&local_bc);
      iVar2 = local_c0;
      if ((*(uint *)(iVar1 + 0x2c) & 4) == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
        if ((*(uint *)(iVar1 + 0x2c) & 8) == 0) {
          iVar2 = iVar2 >> 1;
        }
        iVar2 = local_c0 - iVar2;
      }
      *(int *)(iVar1 + 0x18) = iVar2;
      iVar2 = local_bc;
      if ((*(uint *)(iVar1 + 0x2c) & 1) == 0) {
        iVar2 = *(int *)(iVar1 + 0x14);
        if ((*(uint *)(iVar1 + 0x2c) & 2) == 0) {
          iVar2 = iVar2 >> 1;
        }
        iVar2 = local_bc - iVar2;
      }
      *(int *)(iVar1 + 0x1c) = iVar2;
      break;
    case 3:
      if ((*(uint *)(iVar1 + 0x30) & 4) == 0) {
        local_c0 = param_2[2];
        if ((*(uint *)(iVar1 + 0x30) & 8) == 0) {
          local_c0 = local_c0 >> 1;
        }
        local_c0 = local_c0 + *param_2;
      }
      else {
        local_c0 = *param_2;
      }
      if ((*(uint *)(iVar1 + 0x30) & 1) == 0) {
        if ((*(uint *)(iVar1 + 0x30) & 2) == 0) {
          iVar2 = param_2[1];
          local_bc = param_2[3] >> 1;
        }
        else {
          local_bc = param_2[1];
          iVar2 = param_2[3];
        }
        local_bc = local_bc + iVar2;
      }
      else {
        local_bc = param_2[1];
      }
      iVar2 = local_c0;
      if ((*(uint *)(iVar1 + 0x2c) & 4) == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
        if ((*(uint *)(iVar1 + 0x2c) & 8) == 0) {
          iVar2 = iVar2 >> 1;
        }
        iVar2 = local_c0 - iVar2;
      }
      *(int *)(iVar1 + 0x18) = iVar2;
      iVar2 = local_bc;
      if ((*(uint *)(iVar1 + 0x2c) & 1) == 0) {
        iVar2 = *(int *)(iVar1 + 0x14);
        if ((*(uint *)(iVar1 + 0x2c) & 2) == 0) {
          iVar2 = iVar2 >> 1;
        }
        iVar2 = local_bc - iVar2;
      }
      *(int *)(iVar1 + 0x1c) = iVar2;
      break;
    case 4:
      if ((*(uint *)(iVar1 + 0x30) & 4) == 0) {
        local_c0 = *(int *)(param_3 + 0x5c);
        if ((*(uint *)(iVar1 + 0x30) & 8) == 0) {
          local_c0 = local_c0 >> 1;
        }
      }
      else {
        local_c0 = 0;
      }
      if ((*(uint *)(iVar1 + 0x30) & 1) == 0) {
        local_bc = *(int *)(param_3 + 0x60);
        if ((*(uint *)(iVar1 + 0x30) & 2) == 0) {
          local_bc = local_bc >> 1;
        }
      }
      else {
        local_bc = 0;
      }
      iVar2 = local_c0;
      if ((*(uint *)(iVar1 + 0x2c) & 4) == 0) {
        iVar2 = *(int *)(iVar1 + 0x10);
        if ((*(uint *)(iVar1 + 0x2c) & 8) == 0) {
          iVar2 = iVar2 >> 1;
        }
        iVar2 = local_c0 - iVar2;
      }
      *(int *)(iVar1 + 0x18) = iVar2;
      if ((*(uint *)(iVar1 + 0x2c) & 1) == 0) {
        if ((*(uint *)(iVar1 + 0x2c) & 2) == 0) {
          *(int *)(iVar1 + 0x1c) = local_bc - (*(int *)(iVar1 + 0x14) >> 1);
        }
        else {
          *(int *)(iVar1 + 0x1c) = local_bc - *(int *)(iVar1 + 0x14);
        }
      }
      else {
        *(int *)(iVar1 + 0x1c) = local_bc;
      }
      break;
    default:
      FUN_1000cba0(0x67);
      goto LAB_1003601a;
    }
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 8);
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0xc);
LAB_1003601a:
    if ((((*(int *)(iVar1 + 0x18) < *(int *)(param_3 + 0x5c)) &&
         (0 < *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x18))) &&
        (*(int *)(iVar1 + 0x1c) < *(int *)(param_3 + 0x60))) &&
       (0 < *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x1c))) {
      *(int *)(iVar1 + 0x3c) = param_3;
      *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(param_3 + 0x110);
      *(int *)(param_3 + 0x110) = iVar1;
    }
    iVar1 = *(int *)(iVar1 + 0x38);
  } while( true );
}


