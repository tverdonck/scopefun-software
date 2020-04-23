print_stdout = print

print = function(...)
   local arg = { ... }
   for i,v in ipairs(arg) do
      LuaPrint(v)
   end
end

-- onFrame
function onFrame(data,length,pos,zoom,user)
	return 0
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig,pos,zoom,user)
	if sample%10000 == 0 then 
		ch0  = 500
		ch1  = 400
	end
    return sample,ch0,ch1,fun,dig,pos,zoom,user
end

-- onDisplay
function onDisplay(data,pos,zoom,user)
  return 0
end

-- onConfigure
function onConfigure(hw)
  return 0
end

-- onInit
function onInit(ctx)
  return 0
end

