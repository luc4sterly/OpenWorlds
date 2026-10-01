// 004503a0 FUN_004503a0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_004503a0(void *this,char param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_34;
  undefined2 *local_30;
  undefined4 local_2c;
  undefined2 local_28 [6];
  int local_1c;
  undefined4 local_16;
  
  iVar7 = 0;
  local_34 = 0;
  local_30 = local_28;
  local_2c = (int)&local_16 + 2;
  while( true ) {
    if (local_34 == 0xc) {
      return 0xffffffff;
    }
    puVar2 = *(undefined4 **)((int)this + 0x24);
    iVar5 = FUN_004553d0((int)puVar2,-1);
    if (iVar5 < 0) {
      piVar1 = puVar2 + 0xb;
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      if (iVar5 == 0) {
        uVar6 = FUN_00455440(puVar2);
      }
      else {
        pbVar3 = (byte *)puVar2[10];
        puVar2[10] = puVar2[10] + 1;
        uVar6 = (uint)*pbVar3;
      }
    }
    else {
      uVar6 = 0xffffffff;
    }
    if (uVar6 == 0xffffffff) break;
    *(char *)((int)local_28 + local_34) = (char)uVar6;
    local_30 = (undefined2 *)((int)local_30 + 1);
    local_34 = local_34 + 1;
    cVar4 = (**(code **)(**(int **)((int)this + 0x2c) + 8))
                      ((int)this + 0x28,(int)local_28 + iVar7,local_30,&local_1c,&local_16,local_2c,
                       (int)&local_16 + 2);
    switch(cVar4) {
    case '\x01':
      iVar7 = local_1c - (int)local_28;
      break;
    case '\x02':
      return 0xffffffff;
    case '\x03':
      local_16 = CONCAT22(local_16._2_2_,local_28[0]);
    }
    if (cVar4 != '\x01') {
      if (param_1 != '\0') {
        while (local_34 != 0) {
          uVar6 = FUN_004555b0((int)*(char *)((int)local_28 + local_34 + -1),
                               *(int *)((int)this + 0x24));
          local_34 = local_34 + -1;
          if (uVar6 == 0xffffffff) {
            return 0xffffffff;
          }
        }
      }
      return local_16;
    }
  }
  return 0xffffffff;
}


