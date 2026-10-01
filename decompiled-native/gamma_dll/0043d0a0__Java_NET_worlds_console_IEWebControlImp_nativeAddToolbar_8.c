// 0043d0a0 _Java_NET_worlds_console_IEWebControlImp_nativeAddToolbar@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IEWebControlImp_nativeAddToolbar_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  HINSTANCE hBMInst;
  HWND pHVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  TBBUTTON *pTVar8;
  UINT_PTR wBMID;
  int dyButton;
  int dxBitmap;
  int dyBitmap;
  UINT uStructSize;
  TBBUTTON local_b0 [8];
  
                    /* 0x3d0a0  31  _Java_NET_worlds_console_IEWebControlImp_nativeAddToolbar@8 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar2 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar3 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
  if (puVar3 == (uint *)0x0) {
    puVar3 = FUN_0044e010(0x3c);
    puVar7 = puVar3;
    for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar2,puVar3);
  }
  Ordinal_17();
  piVar6 = &DAT_0047755c;
  pTVar8 = local_b0;
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    pTVar8->iBitmap = *piVar6;
    piVar6 = piVar6 + 1;
    pTVar8 = (TBBUTTON *)&pTVar8->idCommand;
  }
  pTVar8 = local_b0;
  uStructSize = 0x14;
  dyBitmap = 0x17;
  dxBitmap = 0x17;
  dyButton = 0;
  iVar5 = 0;
  iVar2 = 8;
  wBMID = 0x80;
  hBMInst = (HINSTANCE)FUN_0040c110();
  pHVar4 = CreateToolbarEx((HWND)puVar3[1],0x54000101,0x8006,8,hBMInst,wBMID,pTVar8,iVar2,iVar5,
                           dyButton,dxBitmap,dyBitmap,uStructSize);
  puVar3[0xb] = (uint)pHVar4;
  if ((HWND)puVar3[0xb] == (HWND)0x0) {
    FUN_0044d5a0(s_Error_displaying_web_control_too_004775fc);
  }
  else {
    SendMessageA((HWND)puVar3[0xb],0x421,0,0);
  }
  return;
}


