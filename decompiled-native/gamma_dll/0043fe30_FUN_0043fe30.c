// 0043fe30 FUN_0043fe30 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_0043fe30(void *this,LPCSTR param_1)

{
  int *piVar1;
  bool bVar2;
  HRESULT HVar3;
  HCURSOR pHVar4;
  int iVar5;
  WCHAR local_21c [260];
  int *local_14;
  
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)((int)this + 0xc) = 0;
  }
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  HVar3 = CoCreateInstance((IID *)&DAT_00477fdc,(LPUNKNOWN)0x0,1,(IID *)&DAT_00467058,
                           (LPVOID *)((int)this + 0xc));
  if (HVar3 < 0) {
    bVar2 = false;
    *(undefined4 *)((int)this + 0xc) = 0;
  }
  else {
    iVar5 = (**(code **)**(undefined4 **)((int)this + 0xc))
                      (*(undefined4 **)((int)this + 0xc),&DAT_00467188,&local_14);
    if (iVar5 < 0) {
      piVar1 = *(int **)((int)this + 0xc);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)((int)this + 0xc) = 0;
      }
      bVar2 = false;
      *(undefined4 *)((int)this + 0x10) = 0;
      *(undefined4 *)((int)this + 8) = 0;
    }
    else {
      iVar5 = (**(code **)(*local_14 + 0x1c))(local_14,(int)this + 0x10);
      (**(code **)(*local_14 + 8))(local_14);
      if (iVar5 < 0) {
        piVar1 = *(int **)((int)this + 0xc);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)((int)this + 0xc) = 0;
        }
        bVar2 = false;
        *(undefined4 *)((int)this + 0x10) = 0;
        *(undefined4 *)((int)this + 8) = 0;
      }
      else {
        bVar2 = true;
      }
    }
  }
  if (!bVar2) {
    FUN_0044d5a0(s_Can_t_create_filter_graph_for__s_00478030);
    return 0;
  }
  MultiByteToWideChar(0,0,param_1,-1,local_21c,0x104);
  pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetCursor(pHVar4);
  iVar5 = (**(code **)(**(int **)((int)this + 0xc) + 0x34))(*(int **)((int)this + 0xc),local_21c,0);
  pHVar4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  SetCursor(pHVar4);
  if (iVar5 < 0) {
    FUN_0044d5a0(s_Can_t_render_file__s_00478054);
    return 0;
  }
  return 1;
}


