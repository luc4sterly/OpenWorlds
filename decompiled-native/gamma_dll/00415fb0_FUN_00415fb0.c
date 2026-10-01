// 00415fb0 FUN_00415fb0 [Global]
// program: gamma.dll

uint __thiscall FUN_00415fb0(void *this,HWND param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
  for (puVar2 = *(uint **)((int)this + 4); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[4]) {
    if ((HWND)puVar2[1] == param_1) {
      if ((puVar2[2] == param_2) && (puVar2[3] == param_3)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
        return *puVar2;
      }
      FUN_004190a0(*puVar2);
      uVar1 = FUN_00418f30(param_2,param_3,puVar2[1]);
      *puVar2 = uVar1;
      if (*puVar2 != 0) {
        puVar2[2] = param_2;
        puVar2[3] = param_3;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
        return *puVar2;
      }
      if (*(int *)((int)this + 8) == 0) {
        *(undefined4 *)((int)this + 8) = 1;
        MessageBoxA(param_1,s_The_worldsplayer_cannot_render_i_0046fec0,
                    s_Video_Memory_Limitation_0046fea8,0x30);
      }
      FUN_00416160(this,(int *)puVar2);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
      return 0;
    }
  }
  puVar2 = FUN_0044e010(0x18);
  if (puVar2 == (uint *)0x0) {
    FUN_00402800(s_CamCache_0046ffb4,0x6d);
  }
  puVar2[1] = (uint)param_1;
  puVar2[2] = param_2;
  puVar2[3] = param_3;
  uVar1 = FUN_00418f30(param_2,param_3,puVar2[1]);
  *puVar2 = uVar1;
  if (*puVar2 != 0) {
    puVar2[4] = *(uint *)((int)this + 4);
    puVar2[5] = 0;
    if (*(int *)((int)this + 4) != 0) {
      *(uint **)(*(int *)((int)this + 4) + 0x14) = puVar2;
    }
    *(uint **)((int)this + 4) = puVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
    return *puVar2;
  }
  if (*(int *)((int)this + 8) == 0) {
    *(undefined4 *)((int)this + 8) = 1;
    MessageBoxA(param_1,s_The_worldsplayer_cannot_render_i_0046fec0,
                s_Video_Memory_Limitation_0046fea8,0x30);
  }
  FUN_0044e100(puVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004894c8);
  return 0;
}


