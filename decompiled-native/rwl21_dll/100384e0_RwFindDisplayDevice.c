// 100384e0 RwFindDisplayDevice [Global]
// program: RWL21.DLL

int RwFindDisplayDevice(char *param_1,undefined4 *param_2,char *param_3,undefined4 param_4,
                       int param_5,int param_6)

{
  uint *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_1e0;
  int local_1dc;
  int local_1d8;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  undefined4 *local_1c0;
  undefined4 local_1bc [43];
  int local_110;
  uint local_10c;
  char local_108 [256];
  undefined *local_8;
  
                    /* 0x384e0  90  RwFindDisplayDevice */
  local_1cc = 1;
  local_1c8 = 0;
  local_110 = -0x80000000;
  if (param_2 == (undefined4 *)0x0) {
    puVar5 = local_1bc;
    for (iVar3 = 0x2b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    local_1c0 = local_1bc;
  }
  else {
    local_1c0 = param_2;
  }
  do {
    bVar2 = RwExtract(param_1,local_1cc,local_108,0x100);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return local_1c8;
    }
    local_8 = RwOpenDisplayDevice(local_108,param_3);
    if (local_8 != (undefined *)0x0) {
      local_1d0 = 0;
      bVar2 = true;
      iVar3 = RwGetDeviceInfo(0xc,&local_1c4,4);
      if (iVar3 != 0) {
        if ((*(byte *)(local_1c4 + 0x79) & 0x20) == 0) {
          local_1d8 = 4;
        }
        else {
          local_1d8 = 3;
        }
        if (local_1c0[0x18] == 0) {
          local_1d0 = -(*(uint *)(local_1c4 + 0x60) >> 3);
        }
        else {
          bVar2 = local_1c0[0x18] == *(int *)(local_1c4 + 0x60);
        }
        if (local_1c0[0x19] == 0) {
          local_1d0 = local_1d0 - (*(uint *)(local_1c4 + 100) >> 4);
        }
        else if (local_1c0[0x19] != *(int *)(local_1c4 + 100)) {
          bVar2 = false;
        }
        if (local_1c0[0x1a] == 0) {
          local_1d0 = local_1d0 - (*(uint *)(local_1c4 + 0x68) >> 7);
        }
        else if (local_1c0[0x1a] != *(int *)(local_1c4 + 0x68)) {
          bVar2 = false;
        }
        if ((local_1c0[0x1b] != 0) && (*(uint *)(local_1c4 + 0x6c) < (uint)local_1c0[0x1b])) {
          bVar2 = false;
        }
        if (local_1c0[0x1e] == 0) {
          iVar3 = FUN_10038970(*(uint *)(local_1c4 + 0x78) & 0xffffdfff);
          local_1d0 = local_1d0 + iVar3;
        }
        else if ((*(uint *)(local_1c4 + 0x78) & local_1c0[0x1e]) != local_1c0[0x1e]) {
          bVar2 = false;
        }
        for (local_10c = 0; local_10c < 6; local_10c = local_10c + 1) {
          if ((*(uint *)(local_1c4 + 0x7c + local_10c * 4) & local_1c0[local_10c + 0x1f]) !=
              local_1c0[local_10c + 0x1f]) {
            bVar2 = false;
            break;
          }
          if (param_2 == (undefined4 *)0x0) {
            iVar4 = FUN_10038970(*(uint *)(local_1c4 + 0x94 + local_10c * 4));
            iVar3 = FUN_10038970(*(uint *)(local_1c4 + 0x7c + local_10c * 4));
            iVar3 = ((uint)(iVar4 * local_1d8) >> 1) + iVar3;
          }
          else {
            iVar3 = FUN_10038970(*(uint *)(local_1c4 + 0x94 + local_10c * 4) &
                                 local_1c0[local_10c + 0x1f]);
          }
          local_1d0 = local_1d0 + iVar3;
        }
        if ((bVar2) && (local_110 < local_1d0)) {
          if ((*(int *)(local_8 + 0x278) != 0) &&
             (iVar3 = (**(code **)(local_8 + 0x278))(local_8,param_4,param_5,param_6), iVar3 != 0))
          {
            local_1e0 = 0x80000000;
            for (local_1dc = 0; local_1dc < param_5; local_1dc = local_1dc + 1) {
              local_1e0 = local_1e0 & *(uint *)(param_6 + local_1dc * 8);
              puVar1 = (uint *)(param_6 + local_1dc * 8);
              *puVar1 = *puVar1 & 0x7fffffff;
            }
            if (local_1e0 == 0x80000000) {
              local_110 = local_1d0;
              local_1c8 = local_1cc;
            }
          }
          for (local_1dc = 0; local_1dc < param_5; local_1dc = local_1dc + 1) {
            puVar1 = (uint *)(param_6 + local_1dc * 8);
            *puVar1 = *puVar1 & 0x7fffffff;
          }
        }
      }
      RwCloseDisplayDevice((int)local_8);
    }
    local_1cc = local_1cc + 1;
  } while( true );
}


