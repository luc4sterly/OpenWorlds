// 00440460 FUN_00440460 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00440460(void *this,undefined4 param_1)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_e8 [18];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c [18];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  
  CoInitialize((LPVOID)0x0);
  HVar1 = CoCreateInstance((IID *)&DAT_00477c74,(LPUNKNOWN)0x0,1,(IID *)&DAT_00477c84,
                           (LPVOID *)((int)this + 0xc));
  if (HVar1 < 0) {
    FUN_0044d5a0(s_Couldn_t_create_DirectDrawFactor_004780a4);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0xc) + 0xc))
                    (*(int **)((int)this + 0xc),0,param_1,8,0,0,(int)this + 0x10);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_create_DirectDraw_objec_004780cc);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)**(undefined4 **)((int)this + 0x10))
                    (*(undefined4 **)((int)this + 0x10),&DAT_00477c94,(int)this + 0x14);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_get_IDirectDraw3_004780f0);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  puVar3 = local_e8;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_80 = 0x200;
  local_e8[0] = 0x6c;
  local_e8[1] = 1;
  iVar2 = (**(code **)(**(int **)((int)this + 0x14) + 0x18))
                    (*(int **)((int)this + 0x14),local_e8,(int)this + 0x18,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_create_Primary_Surface_0047810c);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x18) + 0x58))(*(int **)((int)this + 0x18),local_e8);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_GetSurfaceDesc_0047812c);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  puVar3 = local_7c;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_7c[3] = local_e8[3];
  local_30 = local_9c;
  local_28 = local_94;
  local_34 = local_a0;
  local_7c[2] = local_e8[2];
  local_2c = local_98;
  local_7c[0] = 0x6c;
  local_18 = local_84;
  local_7c[1] = 0x1007;
  local_14 = 0x40;
  local_24 = local_90;
  iVar2 = (**(code **)(**(int **)((int)this + 0x14) + 0x18))
                    (*(int **)((int)this + 0x14),local_7c,(int)this + 0x1c,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_create_off_screen_Surfa_00478144);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x14) + 0x10))
                    (*(int **)((int)this + 0x14),0,(int)this + 0x20,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Couldn_t_create_Clipper_00478168);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x18) + 0x70))
                    (*(int **)((int)this + 0x18),*(undefined4 *)((int)this + 0x20));
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Call_to_SetClipper_failed_00478180);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x20) + 0x20))(*(int **)((int)this + 0x20),0,param_1);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Call_to_SetHWnd_failed_0047819c);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  return 0;
}


