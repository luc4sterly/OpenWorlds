// 00440fa0 FUN_00440fa0 [Global]
// program: gamma.dll

/* WARNING: Removing unreachable block (ram,0x0044107b) */

undefined4 __fastcall FUN_00440fa0(int param_1)

{
  HRESULT HVar1;
  uint *this;
  int iVar2;
  
  *(undefined4 *)(param_1 + 8) = 0;
  CoInitialize((LPVOID)0x0);
  HVar1 = CoCreateInstance((IID *)&DAT_00477fdc,(LPUNKNOWN)0x0,3,(IID *)&DAT_00467108,
                           (LPVOID *)(param_1 + 0xc));
  if (HVar1 < 0) {
    FUN_0044d5a0(s_Could_not_create_filter_graph__00478354);
    FUN_0044d5a0(&DAT_004780c8);
    return 0;
  }
  this = FUN_0044e010(0x154);
  if (this != (uint *)0x0) {
    FUN_00449f30(this,(undefined4 *)&DAT_004782d0,0,(undefined4 *)0x0);
    *this = (uint)&PTR_FUN_0047891c;
    this[3] = (uint)&PTR_FUN_00478934;
    this[4] = (uint)&PTR_FUN_00478978;
    this[0x2f] = (uint)&PTR_FUN_00478a7c;
    this[0x30] = (uint)&PTR_FUN_00478aa8;
    this[0x53] = 0;
    this[0x54] = 0;
    this[0x50] = 0;
  }
  *(uint **)(param_1 + 0x20) = this;
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 != 0) {
    iVar2 = iVar2 + 0xc;
  }
  *(int *)(param_1 + 0x1c) = iVar2;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0xc))
                    (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                     u_TEXTURERENDERER_004783a0);
  if (-1 < iVar2) {
    *(undefined4 *)(param_1 + 8) = 1;
    return 1;
  }
  FUN_0044d5a0(s_Could_not_add_renderer_filter_to_004783c0);
  FUN_0044d5a0(&DAT_004780c8);
  return 0;
}


