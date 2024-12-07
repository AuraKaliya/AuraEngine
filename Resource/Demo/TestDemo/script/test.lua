package.path="./?.lua;"..package.path;
package.path="./SOURCE/Engine/Script/?.lua;"..package.path;

--package.path="./script/?.lua;"..package.path;

local engine=require "engine";
local object=require "gameobject";

function init(objectId)
    print(" TestDemo testLua init.");
    object.init(objectId);
    print(" TestDemo testLua init. end");
    print(objectId);
end

testname="This is TestDemo testLua.";
flag=false;

function tick()
    --print("====tick.====");
    --print(" objectId = " ..object.Id);

    --HP=getObjectState(object.Id,"Model2DHPBar","nowHP");
    --print("now Hp 1 = " ..HP);
    -- if(flag) then
    -- HP=HP+5;
    -- print("now Hp 2 = " ..HP);
    -- setObjectState(object.Id,"Model2DHPBar","nowHP",HP);
    -- soluteInstruction(object.Id,"TestDemoAttacked","Function",114514,1);
    -- end

    -- if(not flag) then
    -- soluteInstruction(object.Id,"TestDemoAttacked","Function",112423,1);
    -- end
    
    -- HP2=getObjectState(object.Id,"Model2DHPBar","nowHP");
    -- print("now Hp 3 = " ..HP2);
    -- flag= not flag;
    
    --soluteInstruction(object.Id,"TestDemoShowCharacterInfo","Function",4,"hahaha",2);
    --print("====tick.====end");
end
