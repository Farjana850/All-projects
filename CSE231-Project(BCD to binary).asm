;WELCOME TO OUR PROJECT
;DATE 16-12-2021
;An Assembly program which should convert 4 digits BCD number into its binary equivalent  
;INPUT IS 1234H  
;OUTPUT 10011010010

DATA SEGMENT
     MSG DB 'Enter A BCD numner'
     BCD DW 1234H
     TEMP DB ?
     RES  DB 17 DUP ('$')
DATA ENDS


CODE SEGMENT
        ASSUME DS:DATA,CS:CODE


START:       
    MOV AX,DATA
    MOV DS,AX
    
   
    MOV AX,BCD
    MOV BL,AL
    
     
    AND AL,0F0H
    AND BL,0FH
    
     
    MOV CL,04H
    ROL AL,CL
    
     
    MOV CL,10
    MUL CL
    
     
    ADD AL,BL
    MOV TEMP,AL
    
   
    MOV AX,BCD
    MOV AL,AH
    MOV AH,0
    MOV BL,AL 
    
     
    AND AL,0F0H
    AND BL,0FH
    
     
    MOV CL,04H
    ROL AL,CL
    
     
    MOV CL,10
    MUL CL 
    
     
    ADD AL,BL
    
   
    MOV CL,100
    MUL CL
    
   
    MOV BL,TEMP
    MOV BH,0
    ADD AX,BX 
      
      
    LEA SI,RES
    CALL HEX2BIN 
    
   
    LEA DX,RES
    MOV AH,9
    INT 21H 
            
    MOV AH,4CH
    INT 21H        
CODE ENDS  

HEX2BIN PROC NEAR
    MOV CX,0
    MOV BX,2 
    
   
LOOP1: MOV DX,0
       DIV BX
       ADD DL,30H
       PUSH DX
       INC CX
       CMP AX,1
       JG LOOP1
     
       ADD AL,30H
       MOV [SI],AL 
       
     
LOOP2: POP AX
       INC SI
       MOV [SI],AL
       LOOP LOOP2
       RET
       
HEX2BIN ENDP

   
END START
                          