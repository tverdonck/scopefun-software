print_stdout = print

print = function(...)
   local arg = { ... }
   for i,v in ipairs(arg) do
      LuaPrint(v)
   end
end

-- onFrame
function onFrame(data,length,pos,zoom,user)
	return data,length,pos,zoom,user
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig,pos,zoom,user)
	spike = 1000
	if sample%spike == 0 then 
		ch0  = 500
		ch1  = 400
		print(string.format('%d\n',sample) )
	end
	if sample == 0 | sample == 10000 then 
		ch0  = 500
		ch1  = 400
		print(string.format('%d\n',sample) )
	end
    return sample,ch0,ch1,fun,dig,pos,zoom,user
end

-- onDisplay
function onDisplay(data,pos,zoom,user)
  return data,pos,zoom,user
end

-- onConfigure
function onConfigure(hw)
  return hw
end

-- onInit
function onInit(ctx)
  return ctx
end

