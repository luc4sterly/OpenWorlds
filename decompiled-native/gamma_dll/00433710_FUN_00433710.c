// 00433710 FUN_00433710 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00433710(void *this,undefined4 param_1,int param_2,int param_3,float param_4)

{
  float10 fVar1;
  int *piVar2;
  float fVar3;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined **local_54 [4];
  undefined4 local_44 [5];
  int local_30 [2];
  int local_28 [2];
  undefined **local_20;
  undefined4 *local_1c;
  undefined **local_18;
  undefined4 *local_14;
  
  if (*(int **)this == (int *)0x0) {
    return;
  }
  piVar2 = &local_5c;
  (**(code **)(**(int **)this + 0x1c))(piVar2);
  local_60 = local_58;
  local_64 = local_5c;
  (**(code **)(**(int **)this + 0x18))(param_1);
  if (param_2 != 0) {
    (**(code **)(**(int **)this + 0x20))(local_54);
    (**(code **)(**(int **)this + 0x24))(local_44);
    FUN_00434440((int)local_54,(int)local_44,param_2);
    FUN_00428e50(local_44);
    local_54[0] = &PTR_LAB_00473390;
  }
  if ((byte)(param_4 < _DAT_00475300 |
            (byte)((ushort)((ushort)(NAN(param_4) || NAN(_DAT_00475300)) << 10) >> 8)) == 1) {
    param_4 = -param_4;
  }
  fVar1 = (float10)(**(code **)(**(int **)this + 0x2c))();
  fVar3 = (float)(fVar1 * (float10)param_4);
  (**(code **)(**(int **)this + 0x1c))(local_30,param_1,piVar2,fVar3);
  FUN_00427cb0(local_28,local_30,&local_64);
  (**(code **)(**(int **)((int)this + 0x14) + 4))(&local_20,fVar3,local_28);
  FUN_00434350((void *)((int)this + 0x10),(int)&local_20);
  local_20 = &PTR_LAB_00475468;
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f340(local_1c);
  }
  FUN_0042f320(&local_20);
  if (param_3 != 0) {
    (**(code **)(**(int **)((int)this + 0x14) + 8))(&local_18);
    FUN_00434470((int)&local_18,param_3);
    local_18 = &PTR_LAB_00475438;
    if (local_14 != (undefined4 *)0x0) {
      FUN_0042f340(local_14);
    }
    FUN_0042f320(&local_18);
  }
  return;
}


