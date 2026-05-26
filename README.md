# Counter(AXI_Microblaze)

# Summary

- Vivado에서 제공하는 Microblaze를 사용하여 AXI 통신을 구현
- AXI를 사용하여 Basys3 보드에서 Uart를 설치
- 통신을 하여 물리적인 동작과 C언어를 통한 동작을 구현
- **4_Register**를 사용하여 제작
- Vitis를 통한 C언어 제작 및 **Basys3** 동작 실행

# 동작

- **GPIO**를 통해 Led출력
- **Counter**를 통한 FND **0~9999**출력

# Module

- **AXI_Master & Slave**
- **GPIO( 3_State_Buffer)**
- **FND_Controller( for ouput of Data in FND(7-segment)**

<img width="1616" height="715" alt="image" src="https://github.com/user-attachments/assets/cc6d9c29-831f-4a6f-a7d5-a93c0ee4ced8" />


  - Counter Block Diagram 

# 추가사항

- **clk_wiz**: sys_clock
- **Register Setting**
    1. slv_reg0: cr(3_state)
    2. slv_reg1: fnd_out(FND)
    3. slv_reg2:odr(3_state)
    4. slv_reg3: idr( 3_state_data)

## **Counter (AXI_Microblaze) Project Summary**

### **Overview**

- **Objective:** Implement AXI communication using the Microblaze soft processor provided by Vivado.
- **UART Integration:** Configure and install UART on the Basys3 board via the AXI interface.
- **System Implementation:** Realize both physical hardware operations and software-driven control using C programming.
- **Register Design:** Developed using a **4-Register** configuration.
- **Development Flow:** Software development in **Vitis** and hardware execution on the **Basys3** board.

---

### **Operations**

- **GPIO Control:** Output signals to drive LEDs.
- **Counter Display:** Drive a 7-Segment (FND) display to show a counter ranging from **0 to 9999**.

---

### **Modules**

- **AXI Master & Slave:** Core communication interfaces.
- **GPIO:** Includes a **3-State Buffer** for input/output control.
- **FND_Controller:** A dedicated module for displaying data on the 7-Segment (FND) display.

---

### **Block Diagram Component**

- **Counter Block Diagram**

---

### **Additional Specifications & Register Settings**

- **clk_wiz:** System clock generation (sys_clock).
- Register Setting
    1. slv_reg0: cr(3_state)
    2. slv_reg1: fnd_out(FND)
    3. slv_reg2:odr(3_state)
    4. slv_reg3: idr( 3_state_data)
